dnl AX_PROG_CSC
dnl
dnl some ideas for this code have been stolen from 
dnl gettext/example/config/csharpcomp (.m4 | .sh.in)
dnl
dnl generates a script to compile a csharp program and
dnl sets an ac_subst CSC to the script

AC_DEFUN([AX_PROG_CSC],[
   ax_cv_prog_csc_sh="$ac_aux_dir/csharpcomp.sh"
   AC_MSG_CHECKING([for C[#] compiler])
   AC_CACHE_VAL([ax_cv_prog_csc],[
      if test -z "$CSC"; then
         AC_MSG_RESULT([(need to check)])
         for ac_prog in cscc mcs csc
         do AC_CHECK_PROG([CSC], [$ac_prog], [$ac_prog])
            if test -n "$CSC" && \
               $CSC -help >/dev/null 2>/dev/null ; then
             break
             fi
          done
      fi
      if test -n "$CSC" ; then
         ax_cv_prog_csc="$CSC"
         CSC="\$(SHELL) \$(top_builddir)/$ax_cv_prog_csc_sh $ax_cv_prog_csc"
         AC_MSG_RESULT([choosing CSC = $CSC])
      else
         AC_MSG_ERROR([did not find any csharp compiler])
      fi
   ])dnl
   AC_MSG_NOTICE(generating $ax_cv_prog_csc_sh)
   test -d "$ac_aux_dir" || $mkdir_p "$ac_aux_dir"
   cat > $ax_cv_prog_csc_sh <<EOF    
#!/bin/sh
# Compile a C# program.

# Copyright (C) 2003-2005 Free Software Foundation, Inc.
# Written by Bruno Haible <bruno@clisp.org>, 2003.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software Foundation,
# Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */

# This uses the same choices as csharpcomp.c, but instead of relying on the
# environment settings at run time, it uses the environment variables
# present at configuration time.
#
# This is a separate shell script, because the various C# compilers have
# different command line options.
#
# Usage: /bin/sh csharpcomp.sh [OPTION] SOURCE.cs ... RES.resource ...
# Options:
#   -o PROGRAM.exe  or  -o LIBRARY.dll
#                     set the output assembly name
#   -L DIRECTORY      search for C# libraries also in DIRECTORY
#   -l LIBRARY        reference the C# library LIBRARY.dll
#   -O                optimize
#   -g                generate debugging information

# func_tmpdir
# creates a temporary directory.
# Sets variable
# - tmp             pathname of freshly created temporary directory
func_tmpdir ()
{
  # Use the environment variable TMPDIR, falling back to /tmp. This allows
  # users to specify a different temporary directory, for example, if their
  # /tmp is filled up or too small.
  : \[$]{TMPDIR=/tmp}
  {
    # Use the mktemp program if available. If not available, hide the error
    # message.
    tmp=\`(umask 077 && mktemp -d -q "\[$]TMPDIR/gtXXXXXX") 2>/dev/null\` &&
    test -n "\[$]tmp" && test -d "\[$]tmp"
  } ||
  {
    # Use a simple mkdir command. It is guaranteed to fail if the directory
    # already exists.  $RANDOM is bash specific and expands to empty in shells
    # other than bash, ksh and zsh.  Its use does not increase security;
    # rather, it minimizes the probability of failure in a very cluttered /tmp
    # directory.
    tmp=\[$]TMPDIR/gt\[$]\[$]-$RANDOM
    (umask 077 && mkdir "$tmp")
  } ||
  {
    echo "\[$]0: cannot create a temporary directory in $TMPDIR" >&2
    { (exit 1); exit 1; }
  }
}

compiler="\[$]1" ; shift

sed_quote_subst="s/\\([[*? <>]]\\)/\\\\1/g"
options_cscc=
options_mcs=
options_csc="-nologo"
sources=
while test \[$]# != 0; do
  case "\[$]1" in
    -o)
      case "\[$]2" in
        *.dll)
          options_cscc="\[$]options_cscc -shared"
          options_mcs0="\[$]options_mcs0 -target:library"
          options_mcs="\[$]options_mcs -target:library"
          options_csc="\[$]options_csc -target:library"
          ;;
        *.exe)
          options_csc="\[$]options_csc -target:exe"
          ;;
      esac
      options_cscc="\[$]options_cscc -o "\`echo "\[$]2" | sed -e "\[$]sed_quote_subst"\`
      options_mcs0="\[$]options_mcs0 -o "\`echo "\[$]2" | sed -e "\[$]sed_quote_subst"\`
      options_mcs="\[$]options_mcs -out:"\`echo "\[$]2" | sed -e "\[$]sed_quote_subst"\`
      options_csc="\[$]options_csc -out:"\`echo "\[$]2" | sed -e "\[$]sed_quote_subst"\`
      shift
      ;;
    -L)
      options_cscc="\[$]options_cscc -L "\`echo "\[$]2" | sed -e "\[$]sed_quote_subst"\`
      options_mcs0="\[$]options_mcs0 -L "\`echo "\[$]2" | sed -e "\[$]sed_quote_subst"\`
      options_mcs="\[$]options_mcs -lib:"\`echo "\[$]2" | sed -e "\[$]sed_quote_subst"\`
      options_csc="\[$]options_csc -lib:"\`echo "\[$]2" | sed -e "\[$]sed_quote_subst"\`
      shift
      ;;
    -l)
      options_cscc="\[$]options_cscc -l "\`echo "\[$]2" | sed -e "\[$]sed_quote_subst"\`
      options_mcs0="\[$]options_mcs0 -r "\`echo "\[$]2" | sed -e "\[$]sed_quote_subst"\`
      options_mcs="\[$]options_mcs -reference:"\`echo "\[$]2" | sed -e "\[$]sed_quote_subst"\`
      options_csc="\[$]options_csc -reference:"\`echo "\[$]2" | sed -e "\[$]sed_quote_subst"\`
      shift
      ;;
    -O)
      options_cscc="\[$]options_cscc -O"
      options_mcs="\[$]options_mcs -optimize+"
      options_csc="\[$]options_csc -optimize+"
      ;;
    -g)
      options_cscc="\[$]options_cscc -g"
      options_mcs0="\[$]options_mcs0 -g"
      options_mcs="\[$]options_mcs -debug+"
      options_csc="\[$]options_csc -debug+"
      ;;
    -*)
      echo "warning csharpcomp: unknown option '\[$]1'" 1>&2
      options_cscc="\[$]options_cscc \[$]1"
      options_mcs0="\[$]options_mcs0 \[$]1"
      options_mcs="\[$]options_mcs \[$]1"
      options_csc="\[$]options_csc \[$]1"
      ;;
    *.resource)
      options_cscc="\[$]options_cscc -fresources="\`echo "\[$]1" | sed -e "\[$]sed_quote_subst"\`
      options_mcs0="\[$]options_mcs0 -resource:"\`echo "\[$]1" | sed -e "\[$]sed_quote_subst"\`
      options_mcs="\[$]options_mcs -resource:"\`echo "\[$]1" | sed -e "\[$]sed_quote_subst"\`
      options_csc="\[$]options_csc -resource:"\`echo "\[$]1" | sed -e "\[$]sed_quote_subst"\`
      ;;
    *.cs)
      sources="\[$]sources "\`echo "\[$]1" | sed -e "\[$]sed_quote_subst"\`
      ;;
    *)
      echo "csharpcomp: unknown type of argument '\[$]1'" 1>&2
      exit 1
      ;;
  esac
  shift
done

case \`basename "\[$]compiler"\` in
  cscc|cscc-*|cscc[[0123456789]]*|*-cscc)
    test -n "\[$]CSHARP_QUIET" || echo "\[$]compiler" \[$]options_cscc \[$]sources
    exec "\[$]compiler" \[$]options_cscc \[$]sources ;;
  mcs|mcs-*|mcs[[0123456789]]*|*-mcs)
    if "\[$]compiler" -help | grep optimize > /dev/null ; then
      test -n "\[$]CSHARP_QUIET" || echo "\[$]compiler" \[$]options_mcs \[$]sources
      exec "\[$]compiler" \[$]options_mcs \[$]sources
    else
      # mcs prints its errors and warnings to stdout, not stderr. Furthermore it
      # adds a useless line "Compilation succeeded..." at the end. Correct both.
      trap 'rm -rf "\[$]tmp"' 1 2 3 15
      test -n "\[$]CSHARP_QUIET" || echo "\[$]compiler" \[$]options_mcs0 \[$]sources
      "\[$]compiler" \[$]options_mcs0 \[$]sources > "\[$]tmp"/mcs.err
      result=$?
      sed -e "/^Compilation succeeded/d" < "\[$]tmp"/mcs.err 1>&2
      rm -rf "\[$]tmp"
      exit \[$]result
    fi ;;
  csc|csc-*|csc[[0123456789]]*|*-csc)
    test -n "\[$]CSHARP_QUIET" || echo "\[$]compiler" \[$]options_csc \[$]sources
    exec "\[$]compiler" \[$]options_csc \[$]sources ;;
  *)
    echo 'unkown C# compiler '\[$]compiler', please reconfigure' 1>&2
    exit 1
esac
EOF
   AC_SUBST([CSC])
])

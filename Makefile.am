# -*- fill-column: 72 -*-
AUTOMAKE_OPTIONS =		subdir-objects
ACLOCAL_AMFLAGS =		-I build-aux/m4

## Main Automake Call to subdirs     ##

SUBDIRS			=	src

## Open-Transactions Installs        ##

#### opentxs script CLI utility

dist_bin_SCRIPTS		=	scripts/opentxs

#### OT SCRIPTS (headers)

opentxslibdir			=	$(pkglibdir)

dist_opentxslib_SCRIPTS		=	scripts/ot/ot_commands.ot	\
					scripts/ot/otapi.ot		\
					scripts/ot/ot_made_easy.ot	\
					scripts/ot/ot_utility.ot

#### OT docs, licences, info, etc.

opentxsdocdir			=	$(docdir)

dist_opentxsdoc_DATA		=	docs/GETTING-STARTED.txt	\
					docs/INSTALL-Android.txt	\
					docs/INSTALL-Fedora.txt		\
					docs/INSTALL-Debian_Ubuntu.txt	\
					docs/INSTALL-OSX-Homebrew.txt	\
					docs/INSTALL-Windows.txt	\
					docs/SSL-NOTES.txt		\
					docs/WIPE-USERS-ACCOUNTS.txt	\
					docs/CLIENT-COMMANDS.txt	\
					docs/LICENSE-AND-CREDITS.txt	\
					PUBKEY-FellowTraveler.asc	\
					README.md 			\
					VERSION

opentxsdatadir			=	$(pkgdatadir)
dist_opentxsdata_DATA		=	sample-data/command-line-ot.opt	\
					sample-data/user-samples.tar.gz


pkgconfigdir			=	$(libdir)/pkgconfig
pkgconfig_DATA			=	src/opentxs.pc

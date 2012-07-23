# -*- fill-column: 72 -*-
AUTOMAKE_OPTIONS =		subdir-objects
ACLOCAL_AMFLAGS =		-I build-aux/m4

## Main Automake Call to subdirs     ##

SUBDIRS			=	src

## Open-Transactions Installs        ##

#### opentxs script CLI utility

dist_bin_SCRIPTS		=	scripts/opentxs

#### OT script HEADERS

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
					docs/LICENSE-AND-CREDITS.txt	\
					PUBKEY-FellowTraveler.asc	\
					README.md 			\
					VERSION

nobase_dist_opentxsdoc_DATA	=	sample-data/ot-sample-data-clean/ot_init.cfg				\
					sample-data/ot-sample-data-clean/client.cfg				\
					sample-data/ot-sample-data-clean/command-line-ot.opt			\
					sample-data/ot-sample-data-clean/CLIENT-COMMANDS.txt			\
					sample-data/ot-sample-data-clean/client_data/LICENSE-AND-CREDITS.txt	\
					sample-data/ot-sample-data-clean/client_data/wallet.xml			\
					sample-data/ot-sample-data-clean/server.cfg				\
					sample-data/ot-sample-data-clean/server_data/notaryServer.xml

pkgconfigdir			=	$(libdir)/pkgconfig
pkgconfig_DATA			=	src/opentxs.pc

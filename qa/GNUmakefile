#!gmake
#
# Copyright (c) 1997-2002 Silicon Graphics, Inc.  All Rights Reserved.
#
# NB: this GNUmakefile is only for use from within the PCP build tree.  It governs
# only the packaging of the testsuite into the $PCP_VAR_DIR/testsuite directory.
# The nearby GNUmakefile.install file actually governs execution of the testsuite.

TOPDIR = ..
include $(TOPDIR)/src/include/builddefs
-include ./GNUlocaldefs

TESTDIR = $(PCP_VAR_DIR)/testsuite
TESTS	= $(shell sed -n -e '/^[0-9]/s/[ 	].*//p' <group)

SUBDIRS = src pmdas cisco pconf
LCONFIG = localconfig

default_pcp default: new remake check qa_outfiles $(OTHERS) $(SUBDIRS) $(LCONFIG)
	$(SUBDIRS_MAKERULE)

setup: $(SUBDIRS) $(LCONFIG) qa_hosts
	$(SUBDIRS_MAKERULE)

LDIRT += 051.work 134.full.* \
	 *.bak *.bad *.core *.full *.raw *.o core a.out core.* \
	 *.log eek* urk* so_locations tmp.* gmon.out oss.qa.tar.gz \
	 *.full.ok *.new rc_cron_check.clean \
	  make.out qa_hosts qa_outfiles localconfig check.time
	# these ones are links to the real files created when the associated
	# test is run
LDIRT += $(shell [ -f .gitignore ] && grep '\.out$$' .gitignore)

SCRIPTS = mk.localconfig mk.pcpversion mk.qa_hosts mk.variant getpmcdhosts \
	  new check recheck remake findmetric group-stats changeversion \
	  check-gitignore check-group chk.setup show-me disk-work \
	  xlate_2_new_pmns common setup.051

COMMON = common.check common.config common.filter common.install.cisco \
	 common.pcpweb common.product common.rc common.setup

OTHERS = GNUmakefile.install group qa_hosts.master qa_outfiles README \
	 valgrind-suppress sanity.coverage

DOTOUTFILES = $(shell [ -f qa_outfiles ] && cat qa_outfiles || ls -1 | grep '^[0-9]' | grep -v '^[0-9][0-9][0-9]$$' | grep -v '^[0-9][0-9][0-9][0-9]$$' | tee qa_outfiles)
LSRCFILES = $(SCRIPTS) $(COMMON) $(TESTS) $(DOTOUTFILES) $(OTHERS)

qa_outfiles:
	@echo $(DOTOUTFILES) > qa_outfiles

qa_hosts:	qa_hosts.master mk.qa_hosts
	./mk.qa_hosts

localconfig:
	@echo PCP_PLATFORM=$(PCP_PLATFORM) > localconfig
	./mk.pcpversion $(PCP_VERSION) >> localconfig
	@echo 'PCP_EOE_VER=0' >> localconfig
	@echo 'PCP_PRO_VER=0' >> localconfig

install_pcp install: $(SUBDIRS)
ifeq (, $(filter mingw darwin solaris, $(TARGET_OS)))
	$(INSTALL) -m 755 -d $(TESTDIR)
	$(INSTALL) -m 755 $(TESTS) $(TESTDIR)
	$(INSTALL) -m 755 $(SCRIPTS) $(COMMON) $(TESTDIR)
	$(INSTALL) -m 644 $(OTHERS) $(TESTDIR)
	$(INSTALL) -m 644 GNUmakefile.install $(TESTDIR)/GNUmakefile
	$(INSTALL) -m 644 qa_outfiles $(DOTOUTFILES) $(TESTDIR)
	$(SUBDIRS_MAKERULE)
endif

include $(BUILDRULES)
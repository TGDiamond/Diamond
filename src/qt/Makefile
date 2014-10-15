.PHONY: FORCE
all: FORCE
	$(MAKE) -C .. diamond_qt test_diamond_qt
clean: FORCE
	$(MAKE) -C .. diamond_qt_clean test_diamond_qt_clean
check: FORCE
	$(MAKE) -C .. test_diamond_qt_check
diamond-qt diamond-qt.exe: FORCE
	 $(MAKE) -C .. diamond_qt

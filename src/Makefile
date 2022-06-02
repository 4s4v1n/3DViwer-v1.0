
PRO_FILENAME=3DViewer
INSTALL_DIR=application
TECH_SUPPORT_DIR=$(INSTALL_DIR)/tech_support
TAR_NAME=s21_3DViewer2.0.tar
SRC=model/*.cpp controller/*.cpp view/*.cpp
HDR=model/*.h controller/*.h view/*.h

all: dist install dvi tests

install: $(INSTALL_DIR) build
	@cp -r $(PRO_FILENAME).app $(INSTALL_DIR)/
	@rm -rf $(PRO_FILENAME).app
	@make clean

uninstall:
	@rm -rf $(INSTALL_DIR)/3DViewer.app

build: createTempMakefile
	@make -f MakefileTemp

clean: createTempMakefile
	@make -f MakefileTemp clean
	@-rm -rf tests
	@-rm MakefileTemp .qmake.stash *.qrc

distclean: createTempMakefile
	@make -f MakefileTemp distclean
	@-rm -rf $(INSTALL_DIR) .qmake.stash tests

createTempMakefile:
	@qmake -o MakefileTemp $(PRO_FILENAME).pro

run:
	@-./$(INSTALL_DIR)/3DViewer.app/Contents/MacOS/3DViewer

dist: $(INSTALL_DIR)
	@tar -cvf $(INSTALL_DIR)/$(TAR_NAME) ./
	@gzip $(INSTALL_DIR)/$(TAR_NAME)

dvi: $(INSTALL_DIR)/$(TECH_SUPPORT_DIR)
ifeq ($(shell uname),Darwin)
	@open https://github.com/sav1nbrave4code/3DViwer_v1.0
else
	@xdg-open https://github.com/sav1nbrave4code/3DViwer_v1.0
endif

$(INSTALL_DIR)/$(TECH_SUPPORT_DIR):
	@-mkdir $(TECH_SUPPORT_DIR)

$(INSTALL_DIR):
	@-mkdir $(INSTALL_DIR)

linter:
	@python3 ../materials/linters/cpplint.py --filter=-build/include_subdir $(SRC) 

cppcheck:
	@cppcheck --enable=all --language=c++ --suppress=unusedFunction --suppress=missingInclude $(SRC) $(HDR)

tests:
	@g++ model/tests/test.cpp model/matrix/*.cpp -o tests -lgtest
	@./tests


PRO_FILENAME=3DViewer
INSTALL_DIR=application
TECH_SUPPORT_DIR=$(INSTALL_DIR)/tech_support
TAR_NAME=s21_3DViewer2.0.tar

all: dist install dvi tests

install: $(INSTALL_DIR) build
	cp -r $(PRO_FILENAME).app $(INSTALL_DIR)/
	rm -rf $(PRO_FILENAME).app
	make clean

uninstall:
	rm -rf $(INSTALL_DIR)/3DViewer.app

build: createTempMakefile
	make -f MakefileTemp

clean: createTempMakefile
	make -f MakefileTemp clean
	-rm -rf tests
	-rm MakefileTemp .qmake.stash *.qrc

distclean: createTempMakefile
	make -f MakefileTemp distclean
	-rm -rf $(INSTALL_DIR) .qmake.stash tests

createTempMakefile:
	qmake -o MakefileTemp $(PRO_FILENAME).pro

run:
	-./$(INSTALL_DIR)/3DViewer.app/Contents/MacOS/3DViewer

dist: $(INSTALL_DIR)
	tar -cvf $(INSTALL_DIR)/$(TAR_NAME) ./
	gzip $(INSTALL_DIR)/$(TAR_NAME)

dvi: $(INSTALL_DIR)/$(TECH_SUPPORT_DIR)
#	-latex2html sources/dvi/manual.tex -t manual.html -dir $(TECH_SUPPORT)/
#	-open $(TECH_SUPPORT_DIR)/index.html
#	cp sources/dvi/manual.md $(TECH_SUPPORT_DIR)
#	-open $(TECH_SUPPORT_DIR)/manual.md

$(INSTALL_DIR)/$(TECH_SUPPORT_DIR):
	-mkdir $(TECH_SUPPORT_DIR)

$(INSTALL_DIR):
	-mkdir $(INSTALL_DIR)

tests:
	g++ model/tests/test.cpp model/matrix/*.cpp -o tests -lgtest
	./tests

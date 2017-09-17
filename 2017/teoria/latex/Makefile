.PHONY: clean all

LATEX := pdflatex
LATEXFLAGS := 

PDFS := dinamica.pdf

all: $(PDFS)

%.pdf: %.tex
	$(LATEX) $(LATEXFLAGS) $<
	$(LATEX) $(LATEXFLAGS) $<

clean:
	rm -rf ./*.aux ./*.log ./*.tex~ ./*.toc ./*.pdf ./*.tex.backup
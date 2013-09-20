SRCS=$(wildcard *.md)

OBJS=$(SRCS:.md=.pdf)

all: $(OBJS)

%.pdf: %.md
	#g++ $(OPTIONS) $< -o $@
	#pandoc -N --toc -H ~/articulos/articulo.tex -t latex -s > $GARBAGE/$FILE.tex
	pandoc $< -N --toc -s -o $@


clean: 
	rm -f $(OBJS)
	#rm -f tags

.PHONY: all clean

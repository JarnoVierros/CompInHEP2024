all: 
	make normal_distribution_writer
	make normal_distribution_reader

normal_distribution_writer: normal_distribution_writer.cpp
	g++ normal_distribution_writer.cpp $$(root-config --glibs --cflags --libs) -o normal_distribution_writer

normal_distribution_reader: normal_distribution_reader.cpp
	g++ normal_distribution_reader.cpp $$(root-config --glibs --cflags --libs) -o normal_distribution_reader

clean:
	-rm normal_distribution.pdf
	-rm normal_distribution.png
	-rm normal_distribution.root

reset:
	-rm normal_distribution.pdf
	-rm normal_distribution.png
	-rm normal_distribution.root
	-rm normal_distribution_writer
	-rm normal_distribution_reader

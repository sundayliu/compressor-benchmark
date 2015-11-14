#include <stdio.h>
#include <stdlib.h>

#include <string>
using namespace std;

#ifdef HAVE_CONFIG
#include "config.h"
#endif

extern"C"{
	#include <lzf.h>
}

enum CompressorType{
	ZLIB,
	LZO,
	LIBLZF,
	QUICKLZ,
	FASTLZ,
	SNAPPY
};

const char* compressor_names[] = {
	"ZLIB",
	"LZO",
	"LIBLZF",
	"QUICKLZ",
	"FASTLZ",
	"SNAPPY"
};

static struct {
  const char* label;
  const char* filename;
  size_t size_limit;
} test_files[] = {
  { "html", "html", 0 },
  { "urls", "urls.10K", 0 },
  { "jpg", "fireworks.jpeg", 0 },
  { "jpg_200", "fireworks.jpeg", 200 },
  { "pdf", "paper-100k.pdf", 0 },
  { "html4", "html_x_4", 0 },
  { "txt1", "alice29.txt", 0 },
  { "txt2", "asyoulik.txt", 0 },
  { "txt3", "lcet10.txt", 0 },
  { "txt4", "plrabn12.txt", 0 },
  { "pb", "geo.protodata", 0 },
  { "gaviota", "kppkn.gtb", 0 },
};

static inline char* string_as_array(string* str){
	return str->empty()?NULL:&*str->begin();
}

void Compress(const char* input, 
	size_t input_size, 
	CompressorType comp, 
	string* compressed, 
	bool compressed_is_preallocated){
	switch(comp){
		#ifdef LZF_VERSION
	case LIBLZF:
		printf("lzf\n");
		compressed->resize(input_size);
		lzf_compress(input, input_size, string_as_array(compressed),input_size);
		break;
		#endif
	default:
		break;
	}
}


int main(int argc , char* argv[]){
	printf("Hello, benchamrk\n");
	const char* input = "Hello,LZF\n";
	string compressed;
	Compress(input, strlen(input), LIBLZF, &compressed, false);
	return 0;
}
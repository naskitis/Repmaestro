#include <iostream>
#include <seqan/index.h>
#include<fstream>
#include<string>
#include <sys/resource.h>
#include <sys/time.h>

using namespace std;
using namespace seqan;

typedef struct timeval timer;

/* source has been edited by askitisn to allow it to read from a file. Download
 * SeqAn from http://www.seqan.de/, unzip it, then copy this file into the demos
 * directory, overwritting the original index_supermaxrepeats.cpp file.  Then 
 * compile.  It will generate "index_supermaxrepeats" binary that finds supermax
 * repeats with an LCP >= 15.   You can change the LCP below and recompile to 
 * generate a new binary.  
 ***
 * NOTE: This has already been done for you (for lcp 15 and 30), provided as the 
 * binaries index_supermaxrepeats_lcp15_SeQan and index_supermaxrepeats_lcp30_SeQan.
 */
int main (int argc, char **argv)
{
  /* edited here by askitisn to read in a file from disk into one line */
  string line;
  ifstream in (argv[1]);
   timer start, stop;

  if (in.is_open())
  {
    std::getline(in,line);
    in.close();
  }
  else 
  {
    cout << "Unable to open file";
    exit(1);
  }

///We begin with a @Class.String@ to store our sequence.
String<char> myString = line;

///Then we create an @Class.Index@ of this @Class.StringSet@
	typedef Index< String<char> > TMyIndex;
	TMyIndex myIndex(myString);

// askitisn: start internal time.
gettimeofday(&start, NULL);


///To find supermaximal repeats, we use SeqAn's @Spec.SuperMaxRepeats Iterator@ 
///and set the minimum repeat length to 15 or 30.
	Iterator< TMyIndex, SuperMaxRepeats >::Type myRepeatIterator(myIndex, 15);



	while (!atEnd(myRepeatIterator)) 
	{
///A repeat can be represented by its length and positions it occurs at.
///@Function.getOccurrences@ returns an unordered sequence of these positions
///The length of this sequence, i.e. the repeat abundance can be obtained 
///from @Function.countOccurrences@.
		for(unsigned i = 0; i < countOccurrences(myRepeatIterator); ++i)
			cout << getOccurrences(myRepeatIterator)[i] << ", ";

///@Function.repLength@ returns the length of the repeat string.
		cout << repLength(myRepeatIterator) << "   " << endl;

/* askitisn: removed, because we want the output to be more consistent with vmatch/repmaestro
 *  ///The repeat string itself can be determined with @Function.representative@
 *		cout << "\t\"" << representative(myRepeatIterator) << '\"' << endl; 
 */

		++myRepeatIterator;
	}
 

// askitisn: stop internal timer and report results
   gettimeofday(&stop, NULL);

   double search_real_time = 1000.0 * ( stop.tv_sec - start.tv_sec ) + 0.001  
   * (stop.tv_usec - start.tv_usec );
   search_real_time = search_real_time/1000.0;
 
   fprintf(stderr, "Number of seconds taken: %f\n", search_real_time);
	return 0;
}

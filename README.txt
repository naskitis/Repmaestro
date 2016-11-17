RepMaestro Version 4.0
---------------------------------------------------------------------------------------------
Authors: Dr. Nikolas Askitis (askitisn@gmail.com) and Dr. Ranjan Sinha (sinhar@unimelb.edu.au)

NON-COMMERCIAL SOFTWARE ONLY!

The software provided is for non-commercial use only. By using my software, you accept the terms and conditions outlined 
in this README file. Please contact askitisn@gmail.com if you want to use or modify the software in a product 
or commercial/research environment. Thank you.


NON-COMMERCIAL LICENSE
--------------------------------------------------------------------------------------------------------------------

1.  You are being provided with a non-commercial trial version of RepMaestro     
    (herein referred to as the Software) and accompanying documentation, all of which was developed in C/C++ for Linux-based platforms.

2.  A commercial-version of the software is required if you wish to use the Software in your project or product.  The commercial version 
    also offers faster performance and more features.

3.  You agree to not distribute the Software.  

4.  You agree to not reverse-engineer the Software.
      
5.  The Software has been rigorously tested over several years.       
    Nonetheless, you agree that the owner of the Software will not be held responsible or liable (in any way) for any loss or   
    damage caused by defects in the Software.

6.  You agree not to disclose any Software performance results to any third party, document, or research avenue, without written 
    permission from the owners (you will be provided with a registration number and an email address which you will need to cite).
  



1) What is it
----------------------------------------------------------------------------------------------
RepMaestro can find Supermaximal Repeats, Maximal Unique Matches and
Pairwise Branching Tandem Repeats in a scalable manner.  This means
that the software offers linear processing time with memory
consumption that is bound and configurable in size. As a result,
RepMaestro can process very large genome sequences on a system with
limited RAM. Alternative solutions such as Vmatch and MUMmer
typically consume memory in proportion to the size of the sequence and are thus
not scalable solutions.

Please read this README file completely before you use RepMaestro.



2) Legal Notice and Limitations
----------------------------------------------------------------------------------------------
This software is for evaluation purposes only and comes with
absolutely no warranty or liability.  Do not distribute this
software without written permission from the authors. If you
wish to use this software in a commercial environment,
please contact Dr. Nikolas Askitis (askitisn@gmail.com) to arrange
for a commercial license.

2.1)
This version of RepMaestro can not find (maximal unique match) repeats
in the reverse strand, though, it can be readily adapted for this task.
See the paper for more details. 

2.3)
RepMaestro is currently designed to process a 4-alphabet DNA
genome sequence (a, c, t, g).  The 'n' character is optional and
is removed by default. It can handle larger alphabets sizes,
though it has not been tested in this respect, and so, is
not recommended for this release.  

2.4)
The scripts provided will prepare a FastA or plain-text genome sequence for
RepMaestro accordingly. Please use our scripts when preparing datasets,
as detailed below.

2.5) RepMaestro relies on existing software to build an uncompressed
suffix array, LCP array and BWT array on disk. We provide in-memory solutions
(which write the array out to disk upon completion) for your usage.  As a result,
however, limitations imposed by these software (specifically, space requirements)
affect the applicability of RepMaestro (not only RepMaestro but
alternative software too, such as Vmatch and MUMmer).   You can replace
the suffix array, LCP array and BWT array generators with your own,
just so long as the output generated is the same. 

2.6) The current implementation of RepMaestro relies on the third-party
software, "mkvtree32" and "mkvtree64" from Vmatch to build the required
4n and 8n (respectively) uncompressed (unsigned) suffix arrays.   You can replace these
with your own implementation, just so long as the output remains the same. 

 
3) How to use RepMaestro out-of-the-box
----------------------------------------------------------------------------------------------
First, you need to build the dataset repository on a local drive.
You will need a broadband Internet connection (the script will download about 800MB of data) 
and around 100GB of free disk space.

Open up a Linux console and type the following commands:

3.1)
unzip repmaestro.tar.zip;
tar -xvf repmaestro.tar;

For optimal results, unzip RepMaestro on an empty disk that is formatted in JFS (assuming
that you are running a binary Linux distribution such as Fedora or Kubuntu, or XFS
otherwise). This is to help ensure that data is accessed (as much as possible), from the
outer-rim of the disk. You will also need at least 20GB of free space to run the experiments.

3.2)
cd repmaestro/experiments;

3.3)
./build_respoitory.bsh [full-path-to-repository]

full-path-to-repository: is a mandatory argument representing the full path to store the repository. For example:

./build_repository.bsh /mnt/aux_disk/datasets/

If the "/mnt/aux_disk/datasets/" directory does not exist, it will attempt to create it.

For best results, please store the repository on a separate disk that has about
100GB+ of free space. Building the repository may take some time to complete, but you
only need to build it once.

This script will fetch the hg19.2bit human genome from the Internet, break it
down into chromosomes, pre-process each chromosome and merge a
selection together to create the datasets used in our experiments.

The datasets used in our experiments have the trailing name "_repmaestro.dat"
or "repmaestro_mum.dat".


3.4)
Before you can run the experiments, you need to install MUMmer and vmatch (in the correct
place, which we highlight below). These high-quality software products are available for free,
under a non-commercial license agreement. Here is a screen dump of our experiments directory:

naskitis@gigabyte:~/repmaestro/experiments$ ls -al
total 2433
drwxr-xr-x 5 naskitis naskitis    1872 2010-07-16 22:53 .
drwxr-xr-x 4 naskitis naskitis     152 2010-07-16 22:06 ..
drwxr-xr-x 8 naskitis naskitis     256 2010-05-29 10:26 alt_software
lrwxrwxrwx 1 naskitis naskitis      55 2010-05-29 09:08 automate_slb_generation.bsh -> ../data_preparation_scripts/automate_slb_generation.bsh
lrwxrwxrwx 1 naskitis root          53 2010-07-15 08:11 build_mum_slb_array32.bsh -> ../data_preparation_scripts/build_mum_slb_array32.bsh
lrwxrwxrwx 1 naskitis root          53 2010-07-15 08:11 build_mum_slb_array64.bsh -> ../data_preparation_scripts/build_mum_slb_array64.bsh
lrwxrwxrwx 1 naskitis root          53 2010-07-15 08:11 build_mum_slb_array.bsh -> ../data_preparation_scripts/build_mum_slb_array32.bsh
lrwxrwxrwx 1 naskitis naskitis      48 2010-05-29 09:08 build_repository.bsh -> ../data_preparation_scripts/build_repository.bsh
lrwxrwxrwx 1 naskitis root          49 2010-07-15 08:11 build_slb_array32.bsh -> ../data_preparation_scripts/build_slb_array32.bsh
lrwxrwxrwx 1 naskitis root          49 2010-07-15 08:11 build_slb_array64.bsh -> ../data_preparation_scripts/build_slb_array64.bsh
lrwxrwxrwx 1 naskitis root          49 2010-07-15 08:12 build_slb_array.bsh -> ../data_preparation_scripts/build_slb_array32.bsh
lrwxrwxrwx 1 naskitis naskitis      28 2010-07-16 14:21 bwt_gen32 -> alt_software/tools/bwt_gen32
lrwxrwxrwx 1 naskitis naskitis      28 2010-07-16 14:21 bwt_gen64 -> alt_software/tools/bwt_gen64
lrwxrwxrwx 1 naskitis naskitis      53 2010-06-18 19:33 capture_fasta_headers.bsh -> ../data_preparation_scripts/capture_fasta_headers.bsh
-rw-r--r-- 1 naskitis naskitis 1714462 2010-07-16 15:14 chr17_ctg5_hap1.fa
-rw-r--r-- 1 naskitis naskitis  602253 2010-07-16 15:14 chr4_ctg9_hap1.fa
lrwxrwxrwx 1 naskitis naskitis      49 2010-05-29 09:08 clean_and_convert.bsh -> ../data_preparation_scripts/clean_and_convert.bsh
lrwxrwxrwx 1 naskitis naskitis      56 2010-06-17 19:51 clean_and_convert_keep_N.bsh -> ../data_preparation_scripts/clean_and_convert_keep_N.bsh
lrwxrwxrwx 1 naskitis naskitis      53 2010-05-30 10:30 convert_to_upper_case.bsh -> ../data_preparation_scripts/convert_to_upper_case.bsh
lrwxrwxrwx 1 naskitis naskitis      46 2010-05-29 09:08 fasta_to_plain.bsh -> ../data_preparation_scripts/fasta_to_plain.bsh
lrwxrwxrwx 1 naskitis naskitis      62 2010-05-29 09:08 generate_chromosomes_from_hg19.bsh -> ../data_preparation_scripts/generate_chromosomes_from_hg19.bsh
lrwxrwxrwx 1 naskitis naskitis      22 2010-05-29 09:08 gensort -> OzSort/Gensort/gensort
-rwxr-xr-x 1 naskitis naskitis   62331 2010-05-29 09:08 index_supermaxrepeats_lcp15_SeqAn
-rwxr-xr-x 1 naskitis naskitis   62331 2010-05-29 09:08 index_supermaxrepeats_lcp30_SeqAn
lrwxrwxrwx 1 naskitis naskitis      28 2010-07-16 14:20 lcp_gen32 -> alt_software/tools/lcp_gen32
lrwxrwxrwx 1 naskitis naskitis      28 2010-07-16 14:20 lcp_gen64 -> alt_software/tools/lcp_gen64
lrwxrwxrwx 1 naskitis naskitis      42 2010-05-29 09:08 mkvtree32 -> alt_software/vmatch.distribution32/mkvtree
lrwxrwxrwx 1 naskitis naskitis      42 2010-05-29 09:08 mkvtree64 -> alt_software/vmatch.distribution64/mkvtree
lrwxrwxrwx 1 naskitis naskitis      30 2010-05-29 09:08 mummer -> alt_software/MUMmer3.22/mummer
lrwxrwxrwx 1 naskitis naskitis      13 2010-05-29 09:08 ozsort -> OzSort/ozsort
drwxr-xr-x 3 naskitis naskitis     120 2010-05-29 10:13 OzSort
lrwxrwxrwx 1 naskitis naskitis      46 2010-05-29 09:08 plain_to_fasta.bsh -> ../data_preparation_scripts/plain_to_fasta.bsh
lrwxrwxrwx 1 naskitis naskitis      45 2010-05-29 09:08 print_results.bsh -> ../data_preparation_scripts/print_results.bsh
lrwxrwxrwx 1 naskitis naskitis      60 2010-06-19 20:29 print_results_fasta_friendly.bsh -> ../data_preparation_scripts/print_results_fasta_friendly.bsh
lrwxrwxrwx 1 naskitis naskitis      64 2010-06-20 18:49 print_results_fasta_friendly_mum.bsh -> ../data_preparation_scripts/print_results_fasta_friendly_mum.bsh
lrwxrwxrwx 1 naskitis naskitis      13 2010-05-29 09:08 repmaestro -> ../repmaestro
drwxr-xr-x 2 naskitis naskitis    1368 2010-06-22 21:16 results_from_paper
-rwx------ 1 naskitis naskitis    6805 2010-05-30 10:14 run_repmaestro_experiments_mum.bsh
-rwx------ 1 naskitis naskitis    5587 2010-06-22 21:10 run_repmaestro_experiments_mum_nocacheflush.bsh
-rwx------ 1 naskitis naskitis    5920 2010-05-30 10:12 run_repmaestro_experiments_supermax.bsh
-rwx------ 1 naskitis naskitis    7203 2010-05-30 10:14 run_repmaestro_experiments_tandem.bsh
lrwxrwxrwx 1 naskitis naskitis      26 2010-07-16 14:20 slb_gen32 -> alt_software/tools/slb_gen
lrwxrwxrwx 1 naskitis naskitis      37 2010-07-16 14:20 slb_gen_buffered32 -> alt_software/tools/slb_gen_buffered32
lrwxrwxrwx 1 naskitis naskitis      37 2010-07-16 14:20 slb_gen_buffered64 -> alt_software/tools/slb_gen_buffered64
lrwxrwxrwx 1 naskitis naskitis      41 2010-05-29 09:08 vmatch32 -> alt_software/vmatch.distribution32/vmatch
lrwxrwxrwx 1 naskitis naskitis      41 2010-05-29 09:08 vmatch64 -> alt_software/vmatch.distribution64/vmatch



We have provided symbolic links that point to the place where the additional software
needs to be installed. Specifically, take a look at the following:  (Notice how that they are all
broken links, since they point to binaries that don't exist yet). 


lrwxrwxrwx 1 naskitis naskitis    42 2010-05-29 09:08 mkvtree32 -> alt_software/vmatch.distribution32/mkvtree
lrwxrwxrwx 1 naskitis naskitis    42 2010-05-29 09:08 mkvtree64 -> alt_software/vmatch.distribution64/mkvtree
lrwxrwxrwx 1 naskitis naskitis    30 2010-05-29 09:08 mummer -> alt_software/MUMmer3.22/mummer
lrwxrwxrwx 1 naskitis naskitis    41 2010-05-29 09:08 vmatch32 -> alt_software/vmatch.distribution32/vmatch
lrwxrwxrwx 1 naskitis naskitis    41 2010-05-29 09:08 vmatch64 -> alt_software/vmatch.distribution64/vmatch


First up, you need to download MUMmer from http://sourceforge.net/projects/mummer/ 
(MUMmer3.22.tar.gz) and unpack it into the directory:
repmaestro/experiments/alt_software/MUMmer3.22/

This should instantly activate the symbolic link (if it doesn't, double check that the path it
points to is correct). That is:

lrwxrwxrwx 1 naskitis naskitis    30 2010-05-29 09:08 mummer -> alt_software/MUMmer3.22/mummer


Second, you need to download Vmatch (both the 32-bit and 64-bit versions), which can be found at:
http://www.vmatch.de/

Unpack and install the 32-bit version (x86) into:
repmaestro/experiments/alt_software/vmatch.distribution32/

Similarly, unpack and install the 64-bit version (x86_64) into:
repmaestro/experiments/alt_software/vmatch.distribution64/

This should instantly activate the symbolic links (if it doesn't, double check the pointed path). 

lrwxrwxrwx 1 naskitis naskitis    42 2010-05-29 09:08 mkvtree32 -> alt_software/vmatch.distribution32/mkvtree
lrwxrwxrwx 1 naskitis naskitis    42 2010-05-29 09:08 mkvtree64 -> alt_software/vmatch.distribution64/mkvtree
lrwxrwxrwx 1 naskitis naskitis    41 2010-05-29 09:08 vmatch32 -> alt_software/vmatch.distribution32/vmatch
lrwxrwxrwx 1 naskitis naskitis    41 2010-05-29 09:08 vmatch64 -> alt_software/vmatch.distribution64/vmatch


The SeQan binaries have been provided for you as:

-rwxr-xr-x 1 naskitis naskitis 62331 2010-05-29 09:08 index_supermaxrepeats_lcp15_SeqAn
-rwxr-xr-x 1 naskitis naskitis 62331 2010-05-29 09:08 index_supermaxrepeats_lcp30_SeqAn

We had to slightly modify the supermaximal repeat source code so that it could accept a
sequence from a file.  Hence, you don't have to download/prepare the SeQan package.
The binaries are ready for use. Nonetheless, if you still wish to download SeQan, you can find it at
http://www.seqan.de/. In which case, cd into the following directory
"repmaestro/experiments/alt_software/SeQan". There you will find the following files:

@:~/repmaestro/experiments/alt_software/SeQan$ ls -al
total 48
drwxr-xr-x 2 naskitis naskitis   176 2010-05-29 09:43 .
drwxr-xr-x 7 naskitis naskitis   232 2010-05-29 09:08 ..
-rwxr--r-- 1 naskitis naskitis 35821 2010-05-29 09:08 COPYING
-rwxr--r-- 1 naskitis naskitis  7804 2010-05-29 09:08 COPYING.LESSER
-rw-r--r-- 1 naskitis naskitis  2860 2010-05-29 09:41 index_supermaxrepeats.cpp

Unzip the SeQan package into this directory. It will create (amongst others) a "demos" directory.
Copy "index_supermaxrepeats.cpp" into the "demos" directory (to overwrite the original file).
You can then compile the software, keeping in mind that the min LCP (or the minimum length of matches)
is hard-coded into the source, so you will need to recompile if you want to change the LCP (which is why
we provide two binaries, one for an LCP of 15 and another for an LCP of 30). 



3.5)
./run_repmaestro_experiments_supermax.bsh [full-path-to-repository] (enable);
./run_repmaestro_experiments_mum.bsh [full-path-to-repository] (enable);
./run_repmaestro_experiments_tandem.bsh [full-path-to-repository] (enable);

"full-path-to-repository": the full path to the repository that was built in the previous step.

"enable":  An optional argument.  Include the word "enable" to enable cache flushing
           between runs, which is highly recommended for more accurate timings. Leave as blank to
           disable.

As mentioned in step 3.1 above, you should run these experiments on an empty JFS/XFS formatted SATA-II drive.

For example:

./run_repmaestro_experiments_supermax.bsh /mnt/aux_disk/datasets/;

The timing results are stored in files of the following format:
<software-used>.<repeat-type>_lcp<15|30>

Upon completion, the following files should be generated:

vmatch32.mum.results_lcp15
vmatch32.mum.results_lcp30
vmatch32.supermax.results_lcp15
vmatch32.supermax.results_lcp30
vmatch64.mum.results_lcp15
vmatch64.mum.results_lcp30
vmatch64.supermax.results_lcp15
vmatch64.supermax.results_lcp30
vmatch64.tandem.results_lcp16
vmatch64.tandem.results_lcp32
vmatch64.tandem.results_lcp4
vmatch64.tandem.results_lcp8
repmaestro.mum_lcp15
repmaestro.mum_lcp30
repmaestro.supermax_lcp15
repmaestro.supermax_lcp30
repmaestro.tandem_lcp16
repmaestro.tandem_lcp32
repmaestro.tandem_lcp4
repmaestro.tandem_lcp8
repmaestro.unbuff_tandem_lcp16
repmaestro.unbuff_tandem_lcp32
repmaestro.unbuff_tandem_lcp4
repmaestro.unbuff_tandem_lcp8
mummer.mum.results_lcp15
mummer.mum.results_lcp30
seqan.supermax.results_lcp15
seqan.supermax.results_lcp30

To view the results in a more human readable manner, type: ./print_results.bsh <filename>
For example:

./print_results.bsh vmatch32.supermax.results_lcp15;

You can also view our results in the "results_from_paper/" directory.




4) How to use RepMaestro with a user specified genome sequence.
----------------------------------------------------------------------------------------------

4.1)
cd repmaestro/experiments;

4.2)
Type
./build_slb_array32.bsh [filename] y/n (linear)
OR
./build_slb_array64.bsh [filename] y/n (linear)

The 32-bit version generates a 4n suffix array, a 4n LCP array and 1n BWT array,
and later merges them into a 9n SLB array.  Similarly, the 64-bit version
generates an 8n suffix array, an 8n LCP array and a 1n BWT array, then later
merges them into a 17n SLB array.   Use ./build_slb_array32.bsh by default.
Use ./build_slb_array64.bsh if you wish to use RepMaestro with very large
genome sequences (>4GB suffix array). 

The "filename" represents a genome sequence file in FastA format or as
plain-text. This script will clean the file by removing all lines
containing '>' and empty lines, all 'N' characters; it will make sure that
the sequence is represented in all upper-case letters (i.e., no
masking), and it will then collapse the file into a single line, ready for
suffix/lcp/bwt array construction. 

Note: If you have provided "y" as the second parameter, then all
'N' characters will be removed, as mentioned.  If you stated 'n',
then the 'N' characters will be retained.  Also,  this script stores
the FastA header information (i.e., the ">" lines) in the file named
<dataset>.headers.  The format of the <dataset>.headers file is as follows:
<offset> <line number> <header>.  Offset is the number
of bytes (starting from 0) encountered before the current 
">" statement appeared. This does not include the bytes taken up by any
previous ">" lines (if any). Line number means the line number of 
the current ">" (starting from 1). 

The third argument is optional.  Include the word "linear" here, if
you wish to enable 13n LCP generation, defaults to brute-force 5n otherwise.

The resulting file created by the ./build_slb_array.bsh script is called "filename.dat".

This script will then use "filename.dat" to build a suffix array, lcp
array, and bwt array, and merge them together to form the slb array.

Please note:

./build_slb_array32/64.bsh will build you an slb array that can be used
by RepMaestro for supermaximal repeats and tandem repeats.

./build_mum_slb_array32/64.bsh can be used to build you an slb array that can be used
by RepMaestro for Maximal Unique Matching.

We provide two sample sequences (randomly chosen from hg19) which 
you can use to quickly generate a MuM SLB array.  For example,

./build_mum_slb_array32.bsh chr17_ctg5_hap1.fa chr4_ctg9_hap1.fa y/n (linear)

OR

./build_mum_slb_array64.bsh chr17_ctg5_hap1.fa chr4_ctg9_hap1.fa y/n (linear)

(i.e., 32-bit suffix array, 9N SLB, or 64-bit suffix array, 17N SLB)

Note: If you have provided "y" as the third parameter, then all
'N' characters will be removed, as mentioned.  If you stated 'n',
then the 'N' characters will be retained.  Also,  this script stores
the FastA header information (i.e., the ">" lines") in the file named
<dataset>.headers.  

The third argument is optical.  Include the word "linear" here, if
you wish to enable 13n LCP generation, defaults to brute-force 5n otherwise.

The suffix array, lcp array and bwt array generators operate
entirely within main-memory. The lcp generator uses the brute-force
algorithm by default (though, you can also select the linear 13n algorithm). 

Use the "filename.dat" file(s) generated by ./build_slb_array32/64.bsh with
vmatch, MUMMer, SeQan etc.  



5) Using RepMaestro with a user specified genome sequence/SLB.
------------------------------------------------------------------------

Type ./repmaestro.

This will print out the help screen, which explains how to use the software.
Please read it carefully to understand the options and the formats accepted
in this current release.  Note: Repmaestro is was developed and compiled
on a 64-bit system running Linux Kubuntu 10.04 x86_64.


5.1) Supermaximum repeats.

./repmaestro 8n supermax  genome_sequence.dat.slb  30

The first parameter is either 4n or 8n, which tells RepMaestro
that the SLB was build using a 32-bit suffix/lcp array or a 64-bit suffix/lcp
array, respectively.  The second parameter is the type of repeat to find, which in this case is
"supermax". The third parameter is the SLB filename. Third parameter is
the min LCP to consider. In this example, only repeats with an LCP
of 30 or more are reported.


5.2) Maximal Unique Matches (MuM) repeats.

./repmaestro 8n mum  genome_sequence_1#genome_sequence_2.dat.slb  20000000  30

For MuM, an SLB array is composed of two sequences separated by a '#' character.

The first parameter is either 4n or 8n, which tells RepMaestro
that the SLB was build using a 32-bit suffix/lcp array or a 64-bit suffix/lcp
array, respectively.  The second parameter is the type of repeat to find, which in this case is
"mum" (Maximal Unique Match). The third parameter is the SLB filename that consists of two
sequences concatenated together using a '#' char. Third parameter is
the location (in bytes) of '#' from the start of the sequence ---
this is the size (which can be found via the command: ls -al genome_sequence_1) 
of the first sequence "genome_sequence_1", which is say,
20,000,000 bytes.  The last parameter is the min LCP to consider. In this example, 
only repeats with an LCP of 30 or more are reported.


5.3) (pairwise branching) Tandem repeats

./repmaestro 8n tandem genome_sequence.slb  genome_sequence.dat  30

The first parameter is either 4n or 8n, which tells RepMaestro
that the SLB was build using a 32-bit suffix/lcp array or a 64-bit suffix/lcp
array, respectively.  The second parameter is the type of repeat to find, which in this case is
"tandem" which buffers the human-readable genome sequence
in memory. The other option is "tandem_unbuffered", which does not
buffer the text file in-memory, and is thus more memory efficient
and can operate with a bound on memory consumption, but at a cost in
performance (complexity, however, remains linear).

Third parameter is the SLB filename. Fourth parameter is the plain-text human-readable
sequence that was used to construct the SLB.

*** NOTE:  The third parameter must be the file generated by the
./build_slb_array64.bsh script, that is, the ".dat" file.

The last parameter is the min LCP to consider. In this example,
only repeats with an LCP of 30 or more are reported.



6) Output
-----------------------------------------------------------------------------
RepMaestro, much like SeQan and vmatch for example, will print out a list of offsets
which represent the location of the repeat (in bytes) starting from the start
of the sequence (.dat) file.

6.1) The following is an example of a supermax output with an LCP of 10:
28581631, 90054183, 13
38671396, 93387840, 97473606, 13
48576840, 63386074, 14

Considering the first line, we are told that positions 28581631 and 90054183
are the start of a supermaximal repeat, both of which are 13 characters long.
The last value shown in each line is the LCP of the repeat(s) --- the length of
the repeat.


6.2) The following is an example of a Maximal Unique Match output with an LCP of 10:
2745487, 27205002, 18
4865217, 9896514, 22
10596116, 8876678, 19
1440118, 249551, 18

Considering the first line, we are told that positions 2745487 and 27205002
are the start of a maximal unique match repeat that is 18 characters long.


6.3) The following is an example of a (pairwise branching) Tandem Repeat output with an LCP of 10:
34339824, 15
6852079, 12
7687590, 12
19272177, 12
19382285, 12
34339828, 11
13154906, 18

Considering the first line, we are told that position 34339824
is the start of a tandem repeat that is 15 characters long.

7) Printing RepMaestro output in FastA friendly format
--------------------------------------------------------
Please note the following scripts:

 ./print_results_fasta_friendly.bsh      (for supermax and tandem)
 ./print_results_fasta_friendly_mum.bsh  (for maximal unique matches)


These scripts take the output generated by RepMaestro and reformats
it to associate the results with the original Fasta headers.  These
scripts support a multi-fasta file. 

#cat chr2.fa >> chr1.fa;
naskitis@gigabyte:~/repmaestro/experiments$./build_slb_array.bsh chr1.fa y
naskitis@gigabyte:~/repmaestro/experiments$ ls -al chr1.*
-rw-r--r-- 1 naskitis naskitis  502299007 2010-06-20 18:05 chr1.fa
-rw-r--r-- 1 naskitis naskitis  463485139 2010-06-20 18:06 chr1.fa.dat
-rw------- 1 naskitis naskitis  463485140 2010-06-20 18:14 chr1.fa.dat.bwt
-rw------- 1 naskitis naskitis 1853940556 2010-06-20 18:13 chr1.fa.dat.lcp
-rw------- 1 naskitis naskitis 4171366252 2010-06-20 18:15 chr1.fa.dat.slb
-rw-r--r-- 1 naskitis naskitis 1853940556 2010-06-20 18:12 chr1.fa.dat.suf
-rw-r--r-- 1 naskitis naskitis         35 2010-06-20 18:21 chr1.fa.headers

naskitis@gigabyte:~/repmaestro/experiments$./repmaestro  supermax  chr1.fa.dat.slb 8000 > RESULTS; 
#extra values was manually added to RESULTS to better demonstrate formatting.
naskitis@gigabyte:~/repmaestro/experiments$./print_results_fasta_friendly.bsh RESULTS chr1.fa.headers
>CHR1 
125180719, 125175949, 10822
13117088, 12946252, 9827
103114998, 103025265, 11022
103371613, 103465751, 8002
123268356, 124710188, 16206                                                             
124681085, 123239252, 9143
12888126, 13058923, 15745                                                               
124496410, 123054704, (244277328), 14722
124922552, 121285043, 9523                                                              
123465905, 123461140, 15198
13184387, 13013527, 12742
124609910, 123168129, 8165
103126007, 103036275, 67631
123253543, 124695375, 13353
121261896, 124899409, 8355
123203170, 124645006, 11450
>CHR2 
312699599, 312721995, 11373                     
315134782, 315306270, 11434                     
(124496410), (123054704), 244277328, 14722      
244258826, 244277328, 18517

This script works for supermax and tandem outputs. For Maximal Unique Matches, see the following
example using our sample datasets provided in the experiments directory.  The values
shown in parenthesis are explained below. 


naskitis@gigabyte:~/repmaestro/experiments$ ./build_mum_slb_array.bsh chr4_ctg9_hap1.fa chr17_ctg5_hap1.fa y
naskitis@gigabyte:~/repmaestro/experiments$ ls -al chr*
-rw-r--r-- 1 naskitis naskitis    1714462 2010-06-20 20:40 chr17_ctg5_hap1.fa
-rw-r--r-- 1 naskitis naskitis    2171255 2010-06-18 19:49 chr17_ctg5_hap1.fa#chr4_ctg9_hap1.fa.dat
-rw------- 1 naskitis naskitis    2171256 2010-06-18 19:49 chr17_ctg5_hap1.fa#chr4_ctg9_hap1.fa.dat.bwt
-rw------- 1 naskitis naskitis    8685020 2010-06-18 19:49 chr17_ctg5_hap1.fa#chr4_ctg9_hap1.fa.dat.lcp
-rw------- 1 naskitis naskitis   19541296 2010-06-18 19:49 chr17_ctg5_hap1.fa#chr4_ctg9_hap1.fa.dat.slb
-rw-r--r-- 1 naskitis naskitis    8685020 2010-06-18 19:49 chr17_ctg5_hap1.fa#chr4_ctg9_hap1.fa.dat.suf
-rw-r--r-- 1 naskitis naskitis    1580828 2010-06-20 20:40 chr17_ctg5_hap1.fa.dat
-rw------- 1 naskitis naskitis    1580829 2010-06-20 20:40 chr17_ctg5_hap1.fa.dat.bwt
-rw------- 1 naskitis naskitis    6323312 2010-06-20 20:40 chr17_ctg5_hap1.fa.dat.lcp
-rw------- 1 naskitis naskitis   14227453 2010-06-20 20:40 chr17_ctg5_hap1.fa.dat.slb
-rw-r--r-- 1 naskitis naskitis    6323312 2010-06-20 20:40 chr17_ctg5_hap1.fa.dat.suf
-rw-r--r-- 1 naskitis naskitis         21 2010-06-20 20:40 chr17_ctg5_hap1.fa.headers
-rw-r--r-- 1 naskitis naskitis  502299007 2010-06-20 18:05 chr1.fa
-rw-r--r-- 1 naskitis naskitis  463485139 2010-06-20 18:06 chr1.fa.dat
-rw------- 1 naskitis naskitis  463485140 2010-06-20 18:14 chr1.fa.dat.bwt
-rw------- 1 naskitis naskitis 1853940556 2010-06-20 18:13 chr1.fa.dat.lcp
-rw------- 1 naskitis naskitis 4171366252 2010-06-20 18:15 chr1.fa.dat.slb
-rw-r--r-- 1 naskitis naskitis 1853940556 2010-06-20 18:12 chr1.fa.dat.suf
-rw-r--r-- 1 naskitis naskitis         35 2010-06-20 18:21 chr1.fa.headers
-rw-r--r-- 1 naskitis naskitis  248063367 2010-06-20 18:04 chr2.fa
-rw-r--r-- 1 naskitis naskitis     602253 2010-06-20 20:40 chr4_ctg9_hap1.fa
-rw-r--r-- 1 naskitis naskitis    2171255 2010-06-20 20:40 chr4_ctg9_hap1.fa#chr17_ctg5_hap1.fa.dat
-rw------- 1 naskitis naskitis    2171256 2010-06-20 20:40 chr4_ctg9_hap1.fa#chr17_ctg5_hap1.fa.dat.bwt
-rw------- 1 naskitis naskitis    8685020 2010-06-20 20:40 chr4_ctg9_hap1.fa#chr17_ctg5_hap1.fa.dat.lcp
-rw------- 1 naskitis naskitis   19541296 2010-06-20 20:40 chr4_ctg9_hap1.fa#chr17_ctg5_hap1.fa.dat.slb
-rw-r--r-- 1 naskitis naskitis    8685020 2010-06-20 20:40 chr4_ctg9_hap1.fa#chr17_ctg5_hap1.fa.dat.suf
-rw-r--r-- 1 naskitis naskitis     590426 2010-06-20 20:40 chr4_ctg9_hap1.fa.dat
-rw------- 1 naskitis naskitis     590427 2010-06-20 20:40 chr4_ctg9_hap1.fa.dat.bwt
-rw------- 1 naskitis naskitis    2361704 2010-06-20 20:40 chr4_ctg9_hap1.fa.dat.lcp
-rw------- 1 naskitis naskitis    5313835 2010-06-20 20:40 chr4_ctg9_hap1.fa.dat.slb
-rw-r--r-- 1 naskitis naskitis    2361704 2010-06-20 20:40 chr4_ctg9_hap1.fa.dat.suf
-rw-r--r-- 1 naskitis naskitis         20 2010-06-20 20:40 chr4_ctg9_hap1.fa.headers

naskitis@gigabyte:~/repmaestro/experiments$ ./repmaestro mum chr4_ctg9_hap1.fa#chr17_ctg5_hap1.fa.dat.slb 590426 55 > RESULTS_MUM
naskitis@gigabyte:~/repmaestro/experiments$ ./print_results_fasta_friendly_mum.bsh RESULTS_MUM chr4_ctg9_hap1.fa chr17_ctg5_hap1.fa
>CHR4_CTG9_HAP1 
121549, (1115915), 64
65836, 389873, 56
503173, (1118641), 60
110071, 557614, 55
22745, (1180848), 55
276910, 363116, 57
127022, 557587, 77
503176, 343834, 79
60296, 166021, 60
65819, (798361), 69
503202, 113240, 63
503182, (1352011), 80
503362, 37239, 59
126986, (1118612), 77
503178, 178423, 78
77419, (1547155), 61
66790, (748419), 65
287686, (798351), 55
138770, 333880, 64
532905, 485078, 67
83713, (1477586), 59
128547, 333820, 59
300474, (833084), 66
65832, (1412723), 59
101163, 336260, 55
135624, 551894, 59
289057, 19588, 59
114213, (1518027), 60
>CHR17_CTG5_HAP1 
(121549), 1115915, 64
(503173), 1118641, 60                           
(22745), 1180848, 55                            
(65819), 798361, 69                             
(503182), 1352011, 80                           
(126986), 1118612, 77                           
(77419), 1547155, 61                            
(66790), 748419, 65
(287686), 798351, 55
(83713), 1477586, 59                            
(300474), 833084, 66                            
(65832), 1412723, 59
(114213), 1518027, 60             

Notice the different arguments (and file formats) required for this script.  
In particular, you need to pass in the original .fa files. 

The values shown in parentheses represent offsets (locations of repeats) that do
not belong to the current FastA header/sequence, but are associated with a repeat
that does belong to the current FastA header/sequence --- the one(s) shown on the same
line that are printed without parentheses.  Consider the following example
from the results shown above.:

>CHR4_CTG9_HAP1 
121549, (1115915), 64
...
>CHR17_CTG5_HAP1 
(121549), 1115915, 64

We are told that a MuM starts at offset 121549 which belongs to the CR4_CTG9_HAP1
sequence, and is also associated with the repeat at offset 1115915, both of which
are 64 characters long.  However, the repeat  1115915 is shown in parenthesis,
which means that it does not belong to the current sequence/header.  As we can see, 
it belongs to CHR17_CTG5_HAP1, which also reports the associated repeat at
offset 121549 in parentheses.  

8) Software compilation version
------------------------------------------------------------------------------
The software binaries provided were compiled on an AMD 64-bit system
using g++ (Ubuntu 4.4.3-4ubuntu5) 4.4.3 x86_64 platform (Kubunto 10.04 LTS).




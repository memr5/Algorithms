/*
	binary search must receive an ordered array!
*/
int binarySearch( int[] haystack, int needle )
{
	size_t start = 0;
	size_t end = haystack.length;
	while( start < end)
	{
		size_t index = (start + end ) / 2;
		if( haystack[index] == needle ) return index;
		if( needle > haystack[index] )
			start = index + 1;
		else
			end = index;
	}
	return -1;
}

void main()
{
	import std.random : uniform;
	import std.stdio : writeln, readln;
	import std.conv : to;
	import std.string : strip;
	import std.algorithm : sort;
	import std.array : array;

	int[] haystack;

	size_t haystack_size  = 100;
	size_t rnd_low_bound  = 0;
	size_t rnd_high_bound = 100;

	haystack.length = haystack_size;

	//fill array randomly
	foreach(index ; 0 .. haystack_size)
	{
		haystack[index] = cast(int) uniform(rnd_low_bound, rnd_high_bound);
	}
	
	//choose needle	
	writeln("Choose a integer value between ", rnd_low_bound, " and ", rnd_high_bound , " :");
	int needle = readln().strip.to!int;

	haystack = haystack.sort.array;

	int result = binarySearch( haystack, needle );

	if( result == -1 ){
		writeln("The value was not found!");
	} else {
		writeln("The first occurence of the value are in the ", result, " position of the array");
	}

	writeln("Array Values:");
	writeln(haystack);
}
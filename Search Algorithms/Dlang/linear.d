int linearSearch( int[] haystack, int needle )
{
	foreach(index, value ; haystack)
	{
		if( needle == value ) return index;
	}
	return -1;
}

void main()
{
	import std.random : uniform;
	import std.stdio : writeln, readln;
	import std.conv : to;
	import std.string : strip;

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

	int result = linearSearch( haystack, needle );

	if( result == -1 ){
		writeln("The value was not found!");
	} else {
		writeln("The first occurence of the value are in the ", result, " position of the array");
	}

	writeln("Array Values:");
	writeln(haystack);

}
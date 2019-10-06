fun <T : Comparable<T>> List<T?>.binarySearch(element: T?, fromIndex: Int = 0, toIndex: Int = size): Int {

    var begin = fromIndex
    var end = toIndex - 1

    while (begin <= end) {
        val mid = (begin + end) / 2
        val midVal = get(mid)
        val compare = compareValues(midVal, element)

        when {
            compare < 0 -> begin = mid + 1
            compare > 0 -> end = mid - 1
            else -> return mid
        }
    }
    return -1;
}



fun main(args: Array<String>) {
    val arr = intArrayOf(3, 2, 5, 9, 1).sorted()
    val testOne = 2
    val testTwo = 9

    val a = arr.binarySearch(testOne)
    println(if (a < 0) "$testOne not found" else "$testOne found at index $a")

    val b = arr.binarySearch(testTwo)
    println(if (b < 0) "$testTwo not found" else "$testTwo found at index $b")
}
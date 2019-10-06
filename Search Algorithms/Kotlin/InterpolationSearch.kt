fun interpolationSearch(arr: IntArray, item: Int): Int {
    var hi = arr.size - 1
    var lo = 0
    while (item >= arr[lo] && item <= arr[hi] && lo <= hi) {
        val probe =
            lo + (hi - lo) * (item - arr[lo]) / (arr[hi] - arr[lo])
        if (hi == lo) {
            return if (arr[lo] == item) {
                lo
            } else {
                -1
            }
        }
        if (arr[probe] == item) {
            return probe
        }
        if (arr[probe] < item) {
            lo = probe + 1
        } else {
            hi = probe - 1
        }
    }
    return -1
}


fun main(args: Array<String>) {
    var arr = intArrayOf(
        2, 3, 5, 6, 8, 11, 15, 19, 21, 24,
        28, 31, 44, 55, 76
    )
    val x = 31
    val xIndex = interpolationSearch(arr, x)

    if (xIndex != -1) println("Item $x found at index $xIndex") else println("Element $x not found.")

    val y = 1
    val yIndex = interpolationSearch(arr, y)

    if (yIndex != -1) println("Item $x found at index $yIndex") else println("Element $x not found.")
}

fun linearSearch(arr: IntArray, key: Int) {
    for (i in arr.indices) if (arr[i] == key) {
        println("$key found at position $i")
        return
    }
    println("$key not found")
}

fun main(args: Array<String>) {
    val arr = intArrayOf(9, 3, 1, 4, 5)
    linearSearch(arr, 4)
    linearSearch(arr, 2)
}


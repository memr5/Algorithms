fun factorial() {
    val num = 9
    var factorial: Long = 1
    for (i in 1..num) {
        factorial *= i.toLong()
    }
    println("the factorial of $num is $factorial")

}

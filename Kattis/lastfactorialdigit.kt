// Last Factorial Digit

fun main() {
    val T = readLine()!!.toInt()
    for (i in 1..T){
        val N = readLine()!!.toInt()
        var fact = 1
        for(i in 1..N)
            fact *= i
        println(fact % 10)
    }
}

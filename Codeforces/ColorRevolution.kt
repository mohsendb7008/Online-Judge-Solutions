fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val(n, k) = readLine()!!.split(" ").map { it.toLong() }
        val n1 = n / (1 + k + k * k + k * k * k)
        println("$n1 ${k * n1} ${k * k * n1} ${k * k * k * n1}")
    }
}
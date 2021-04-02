fun main() {
    val q = readLine()!!.toInt()
    repeat(q){
        val n = readLine()!!.toInt()
        val sum = readLine()!!.split(" ").map { it.toInt() }.sum()
        println(sum / n + if(sum % n == 0) 0 else 1)
    }
}
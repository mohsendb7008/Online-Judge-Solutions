fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val(a, b, k) = readLine()!!.split(" ").map { it.toLong() }
        println((k / 2) * (a - b) + (k % 2) * a)
    }
}
fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        readLine()!!
        val(a, va) = readLine()!!.split(" ").map { it.toInt() }
        val(_, vc) = readLine()!!.split(" ").map { it.toInt() }
        val b = readLine()!!.toInt()
        println(minOf(va + b - a, vc))
    }
}
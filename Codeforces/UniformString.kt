fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val(n, k) = readLine()!!.split(" ").map { it.toInt() }
        println(('a'..'z').take(k).joinToString(separator = "").repeat(n / k + 1).take(n))
    }
}
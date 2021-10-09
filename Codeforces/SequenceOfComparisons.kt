fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val s = readLine()!!
        val b = s.count { it == '>' }
        val l = s.count { it == '<' }
        println(when {
            b > 0 && l > 0 -> "?"
            b > 0 -> ">"
            l > 0 -> "<"
            else -> "="
        })
    }
}
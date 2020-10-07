fun main() = (readLine() to readLine()!!.split(" ").map { it.toInt() }).second.reversed().distinct().also {
    println(it.size)
}.reversed().joinToString(" ").let(::println)
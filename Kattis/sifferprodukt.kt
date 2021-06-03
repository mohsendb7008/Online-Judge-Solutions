// Digit Product

fun main() {
    var n = readLine()!!.toInt()
    while (n >= 10)
        n = n.toString().filter { it != '0' }.map { it.toInt() - '0'.toInt() }.fold(1, {acc, it -> acc * it})
    println(n)
}
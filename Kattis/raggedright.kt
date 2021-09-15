// Ragged Right

fun main() {
    val lines = generateSequence(::readLine).toList()
    val maxLineLength = lines.maxByOrNull { it.length }!!.length
    println(lines.dropLast(1).sumOf { (maxLineLength - it.length) * (maxLineLength - it.length) })
}

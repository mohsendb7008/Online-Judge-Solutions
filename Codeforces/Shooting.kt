fun main() {
    readLine()
    val a = readLine()!!.split(" ").map { it.toInt() }.withIndex().sortedByDescending { it.value }
    println(a.foldIndexed(0) { index, acc, it -> acc + index * it.value + 1 })
    println(a.joinToString(separator = " ") { (it.index + 1).toString() })
}
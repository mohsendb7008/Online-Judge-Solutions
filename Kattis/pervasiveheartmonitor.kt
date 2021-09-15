// Pervasive Heart Monitor

fun main() {
    while (true) {
        val line = readLine() ?: break
        print(line.split(" ").mapNotNull { it.toDoubleOrNull() }.average())
        print(" ")
        print(line.split(" ").filter { it.toDoubleOrNull() == null }.joinToString(separator = " "))
        println()
    }
}
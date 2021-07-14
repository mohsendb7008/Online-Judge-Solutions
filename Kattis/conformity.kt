// Conformity

fun main() {
    val data = HashMap<HashSet<Int>, Int>()
    repeat(readLine()!!.toInt()) {
        val set = readLine()!!.split(" ").map { it.toInt() }.toHashSet()
        data[set] = data.getOrDefault(set, 0) + 1
    }
    val maxFrequency = data.values.maxOrNull()!!
    println(data.values.filter { it == maxFrequency }.sum())
}
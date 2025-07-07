data class Juice(val happiness: Long, val volume: Long)

fun main() {
    val (n, capInput) = readln().split(" ").map { it.toLong() }
    val juices = mutableListOf<Juice>()

    repeat(n.toInt()) {
        val (h, v) = readln().split(" ").map { it.toLong() }
        juices.add(Juice(h, v))
    }

    juices.sortWith(compareByDescending { it.happiness.toDouble() / it.volume })

    var remaining = capInput
    var result = 0.0

    for (juice in juices) {
        if (remaining == 0L) break

        if (juice.volume <= remaining) {
            result += juice.happiness.toDouble()
            remaining -= juice.volume
        } else {
            result += juice.happiness.toDouble() * remaining / juice.volume
            remaining = 0
        }
    }

    println("%.5f".format(result))
}

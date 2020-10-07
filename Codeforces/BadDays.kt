import java.util.*

data class Pack(val value: Int, val index: Int): Comparable<Pack>{

    override fun compareTo(other: Pack): Int {
        val prior = value.compareTo(other.value)
        if(prior == 0)
            return index.compareTo(other.index)
        return prior
    }
}

val days = TreeSet<Pack>()

fun main() {
    val n = readLine()!!.toInt()
    val arr = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
    var ans = 0
    for(i in 0 until n){
        val it = days.iterator()
        if(days.size >= 2 && it.next().value < -arr[i] && it.next().value < -arr[i])
                ans++
        days.add(Pack(-arr[i], i))
    }
    println(ans)
}
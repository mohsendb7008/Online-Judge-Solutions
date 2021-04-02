object ServiceLane {
    fun solve(){
        val t = readLine()!!.split(" ").map { it.toInt() }[1]
        val lane = readLine()!!.split(" ").map { it.toInt() }.toMutableList()
        repeat(t){
            val(i, j) = readLine()!!.split(" ").map { it.toInt() }
            println(lane.subList(i, j+1).min()!!)
        }
    }
}

fun main() = ServiceLane.solve()
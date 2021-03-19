import kotlin.math.min

object BookQueries {
    fun solve(){
        var(lPtr, rPtr) = -1 to 1
        val place = IntArray(200001)
        val q = readLine()!!.toInt()
        place[readLine()!!.split(" ")[1].toInt()] = 0
        repeat(q-1){
            val(c, x) = readLine()!!.split(" ")
            when(c){
                "L" -> place[x.toInt()] = lPtr--
                "R" -> place[x.toInt()] = rPtr++
                else -> println(min(rPtr-place[x.toInt()]-1, place[x.toInt()]-lPtr-1))
            }
        }
    }
}

fun main() = BookQueries.solve()
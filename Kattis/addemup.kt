import java.lang.StringBuilder
import java.util.*

// Add 'Em Up!

object AddEmUpSolver {

    private fun flipOrientation(card: String):String? {
        val builder = StringBuilder()
        for (c in card) {
            builder.append(
                when (c) {
                    '1' -> '1'
                    '2' -> '2'
                    '5' -> '5'
                    '6' -> '9'
                    '8' -> '8'
                    '9' -> '6'
                    '0' -> '0'
                    else -> return null
                }
            )
        }
        return builder.toString().reversed()
    }


    fun solve(): Boolean{
        val s = readLine()!!.split(" ")[1].toInt()
        val cards = readLine()!!.split(" ").toList()
        val (map, flippedMap) = TreeMap<Int, Int>() to TreeMap<Int, Int>()
        for(card in cards){
            map[card.toInt()] = map.getOrDefault(card.toInt(), 0) + 1
            flipOrientation(card)?.let {
                flippedMap[it.toInt()] = flippedMap.getOrDefault(it.toInt(), 0) + 1
            }
        }
        for(card in cards){
            val a = card.toInt()
            if(s == 2 * a && map.getOrDefault(a, 0) > 1)
                return true
            if(s != 2 * a && s - a in map)
                return true
            val f = flipOrientation(card)?.toInt()
            if(f == s - a && flippedMap.getOrDefault(f, 0) > 1)
                return true
            if(f != s - a && s - a in flippedMap)
                return true
            f?.let {
                if(s == 2 * it && flippedMap.getOrDefault(it, 0) > 1)
                    return@solve true
                if(s != 2 * it && s - it in flippedMap)
                    return@solve true
            }
        }
        return false
    }
}

fun main() = println(if(AddEmUpSolver.solve()) "YES" else "NO")
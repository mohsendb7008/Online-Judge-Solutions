import kotlin.math.max
import kotlin.math.min

object TwoPolicemen {
    fun solve(){
        repeat(readLine()!!.toInt()){
            val(n, x, y) = readLine()!!.split(" ").map { it.toInt() }
            var ans = Int.MAX_VALUE
            val(a, b) = min(x, y) to max(x, y)
            for(c in a until b)
                ans = min(ans, max(c-a + a-1 + min(c-a, a-1), n-b + b-c-1 + min(n-b, b-c-1)))
            println(ans)
        }
    }
}

fun main() = TwoPolicemen.solve()
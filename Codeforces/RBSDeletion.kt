import kotlin.math.min

object RBSDeletion {
    fun solve(){
        repeat(readLine()!!.toInt()){
            val(n, k) = readLine()!!.split(" ").map { it.toInt() }
            val s = readLine()!!
            var(open, a, b) = listOf(0, 0, 0)
            for(c in s){
                when(c){
                    '(' -> open++
                    ')' -> {
                        if(open == 1)
                            a++
                        else
                            b++
                        open--
                    }
                }
            }
            println(a + min(b, k))
        }
    }
}

fun main() = RBSDeletion.solve()
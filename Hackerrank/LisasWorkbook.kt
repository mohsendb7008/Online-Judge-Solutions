object LisasWorkbook {
    fun solve(){
        var(k, ans, page) = listOf(readLine()!!.split(" ").map { it.toInt() }[1], 0, -1)
        readLine()!!.split(" ").map { it.toInt() }.forEach {
            repeat(it){ prob ->
                if(prob % k == 0)
                    page++
                if(prob == page)
                    ans++
            }
        }
        println(ans)
    }
}

fun main() = LisasWorkbook.solve()
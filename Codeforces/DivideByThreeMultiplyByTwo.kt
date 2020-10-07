val id = HashMap<Long, Int>()
lateinit var numbers: LongArray
val nexty = IntArray(103){-1}
val indeg = IntArray(103){0}

fun path(node: Int){
    print("${numbers[node]} ")
    if(nexty[node] != -1)
        path(nexty[node])
}

fun main() {
    val n = readLine()!!.toInt()
    numbers = readLine()!!.split(" ").map{ it.toLong() }.toLongArray()
    for(i in 0 until n)
        id[numbers[i]] = i
    for(i in 0 until n){
        var cand = numbers[i] * 2
        if(cand in id) {
            val x = id[cand]!!
            nexty[i] = x
            indeg[x] = 1
        }
        if(numbers[i] % 3L == 0L){
            cand = numbers[i] / 3L
            if(cand in id){
                val x = id[cand]!!
                nexty[i] = x
                indeg[x] = 1
            }
        }
    }
    for(i in 0 until n)
        if(indeg[i] == 0){
            path(i)
            break
        }
}

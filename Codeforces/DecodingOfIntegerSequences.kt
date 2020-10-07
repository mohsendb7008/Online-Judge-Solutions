import java.util.*
import kotlin.collections.ArrayList

fun main() {
    val m = readLine()!!.toInt()
    val arr = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
    val n = arr.count { it == -1 }
    val seq = Array(n){ArrayList<Int>()}
    val link = LinkedList<Int>()
    for(i in 0 until n)
        link.add(i)
    var it = link.iterator()
    for(i in 0 until m){
        if(!it.hasNext())
            it = link.iterator()
        val x = it.next()
        if(arr[i] == -1)
            it.remove()
        else
            seq[x].add(arr[i])
    }
    println(n)
    for(i in 0 until n){
        print("${seq[i].size} ")
        for(j in seq[i])
            print("$j ")
        println()
    }
}
import java.util.*
import kotlin.collections.HashSet

const val MAXN = 200003

val nodes = HashSet<Int>()
val adj = Array(MAXN){HashSet<Int>()}
val queue = LinkedList<Int>()

fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val n = readLine()!!.toInt()
        val c = readLine()!!.split(" ").map { it.toInt() }.toMutableList()
        val d = readLine()!!.split(" ").map { it.toInt() }.toMutableList()
        nodes.clear()
        for(i in 0 until n) {
            nodes.add(i)
            adj[i].clear()
        }
        for(i in 0 until n-1){
            val(x, y) = readLine()!!.split(" ").map { it.toInt() }
            adj[x-1].add(y-1)
            adj[y-1].add(x-1)
        }
        queue.clear()
        for(i in 0 until n)
            if(adj[i].size <= 1 && c[i] == d[i])
                queue.push(i)
        while(queue.isNotEmpty()){
            val u = queue.poll()
            if(u !in nodes)
                continue
            for(v in adj[u]){
                adj[v].remove(u)
                if(c[v] == d[v] && adj[v].size <= 1)
                    queue.push(v)
            }
            adj[u].clear()
            nodes.remove(u)
        }
        if(nodes.isEmpty()){
            println("Yes")
            println(0)
        }
        else{
            val endpoints = mutableListOf<Int>()
            var ok = true
            for(u in nodes){
                if(adj[u].size == 1)
                    endpoints.add(u)
                else if(adj[u].size != 2){
                    ok = false
                    break
                }
            }
            if(!ok || endpoints.size != 2)
                println("No")
            else{
                val path = mutableListOf(endpoints[0])
                var prev = adj[endpoints[0]].first()
                while(prev != endpoints[1]){
                    var next = 0
                    for(v in adj[prev])
                        if(v != path.last()){
                            next = v
                            break
                        }
                    path.add(prev)
                    prev = next
                }
                path.add(endpoints[1])
                var circular = true
                for(i in 0 until path.size)
                    if(c[path[i]] != d[path[(i - 1 + path.size) % path.size]]){
                        circular = false
                        break
                    }
                if(circular){
                    println("Yes")
                    println(path.size)
                    println(path.map { it + 1 }.joinToString(" "))
                }
                else{
                    circular = true
                    for(i in 0 until path.size)
                        if(c[path[i]] != d[path[(i + 1) % path.size]]){
                            circular = false
                            break
                        }
                    if(circular){
                        println("Yes")
                        println(path.size)
                        println(path.reversed().map { it + 1 }.joinToString(" "))
                    }
                    else
                        println("No")
                }
            }
        }
    }
}
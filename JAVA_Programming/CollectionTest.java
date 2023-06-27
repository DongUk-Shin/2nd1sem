import java.util.*;
import java.util.stream.Stream;

public class CollectionTest {
    public static void main(String[] args) {
        ArrayList<String> a = new ArrayList<>(); //ArrayList
        a.add("ArrayList A");
        a.add("ArrayList B");
        a.add("ArrayList C");

        for (String ele : a)  //for each
            System.out.println(ele + " ");
        
        Vector<String> vc = new Vector<>(); //Vector
        vc.add("Vector A");
        vc.add("Vector B");
        vc.add("Vector C");

        Stream <String> s = vc.stream(); //Stream API
        s.forEach(System.out::println);
    
        LinkedList<String> link = new LinkedList<>(); //LinkedList
        link.add("Link A");
        link.addFirst("Link first");
        
        Iterator <String> it = link.iterator(); //Iterator
        while (it.hasNext()) {
            String element = it.next();
            System.out.println(element + "");
        }

        Map<String, String> h = new HashMap<>(); //map
        h.put("A", "a");
        h.put("B", "b");
        h.put("C", "c");

        for (String key : h.keySet()) {
            String value = h.get(key);
            System.out.println("Key: "+ key +" Value: " + value);
        }
    }
}

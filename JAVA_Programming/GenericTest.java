

public class GenericTest { //제네릭 클래스
    public static class MyGeneric<T> {
        private T data;

        public void setData(T data) {
            this.data = data;
        }
        public T getData() {
            return data;
        }
    }

    public static <T> void printArray(T[] array) { //제네릭 메소드
        for (T element : array) {
            System.out.print(element+ " ");
        }
    }

    public static void main(String[] args) {
        MyGeneric<Integer> intObj = new MyGeneric<>();
        intObj.setData(10);
        int data = intObj.getData();
        System.out.println("int: "+ data);

        MyGeneric<String> stringObj = new MyGeneric<>();
        stringObj.setData("Hello");
        String data2 = stringObj.getData();
        System.out.println("string: "+ data2);


        Integer[] intArray = {1, 2, 3, 4, 5};
        String[] stringArray = {"Hello", "World"};
        
        printArray(intArray); // Integer 배열 출력
        printArray(stringArray); // String 배열 출력
    }
}


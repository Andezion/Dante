mod custom_array;
fn main() {
    let mut input: String = String::new();
    println!("Enter: ");

    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let size: usize = input.trim().parse().expect("Incorrect parse");

    if size == 0 {
        panic!("Incorrect input data");
    }

    let mut a: custom_array::ArrayT = Default::default();
    custom_array::array_create(&mut a, size);

    println!("Enter: ");
    loop {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Incorrect input");
        let number: i32 = input.trim().parse().expect("Incorrect parse");

        if number == 0 {
            break;
        }

        match custom_array::array_push_back(&mut a, number) {
            1 => panic!("Incorrect input data"),
            2 => break,
            _other => continue
        }
    }

    if a.size == 0 {
        println!("Buffer is empty");
        return;
    }
    if a.size == a.capacity {
        println!("Buffer is full");
        return;
    }

    custom_array::array_display(&a);
}

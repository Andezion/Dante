use crate::custom_array::array_display;

mod custom_array;

fn main() {
    let mut input: String = String::new();

    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let size: usize = input.trim().parse().expect("Incorrect parse");

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

    let mut odd: custom_array::ArrayT = Default::default();
    let mut even: custom_array::ArrayT = Default::default();

    match custom_array::array_separate(&a, &mut even, &mut odd) {
        -1 => panic!("Incorrect parameters"),
        0 => {
            array_display(&even);
            array_display(&odd);
        }
        1 => println!("Both structs is empty"),
        _other => {
            array_display(&odd);
            array_display(&even);
        }
    }
}

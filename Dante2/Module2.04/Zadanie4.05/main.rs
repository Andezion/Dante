fn create_array(size: i32) -> Vec<i32> {
    if size <= 0 {
        panic!("Incorrect size");
    }

    let array: Vec<i32> = vec![0; size as usize];
    array
}

fn copy_array(array: &Vec<i32>, size: i32) -> Vec<i32> {
    let mut copy_array: Vec<i32> = vec![0; size as usize];
    for i in 0..array.len() {
        copy_array[i] = array[i];
    }
    copy_array
}

fn display_array(array: Vec<i32>) {
    for i in 0..array.len() {
        print!("{} ", array[i]);
    }
    println!();
}

fn main() {
    let mut input: String = String::new();

    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let size: i32 = input.trim().parse().expect("Incorrect parse");

    let mut array: Vec<i32> = create_array(size);

    println!("Enter: ");
    for i in 0..size {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Incorrect input");
        array[i as usize] = input.trim().parse().expect("Incorrect parse");
    }

    let array_copy: Vec<i32> = copy_array(&array, size);

    display_array(array);
    display_array(array_copy);
}

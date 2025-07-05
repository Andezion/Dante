use std::io::Read;

mod vector_utils;

fn main()
{
    let mut array:[i32; 150] = [0; 150];
    println!("Enter: ");

    let mut size: i32 = vector_utils::read_vector(&mut array, 150, 0);
    if size == -1 || size < 1
    {
        panic!("Incorrect input");
    }
    if size > 150
    {
        size = 150;
    }

    let mut input: String = String::new();
    println!("Enter: ");

    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let pos: i32 = input.trim().parse().expect("Incorrect parsing");

    input.clear();
    println!("Enter: ");

    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let dir: i32 = input.trim().parse().expect("Incorrect parsing");

    if dir == 1
    {
        if vector_utils::shift(&mut array, size as usize, pos, vector_utils::Direction::RotateRight) != 0
        {
            panic!("Incorrect data!");
        }
    }
    else
    {
        if vector_utils::shift(&mut array, size as usize, pos, vector_utils::Direction::RotateLeft) != 0
        {
            panic!("Incorrect data!");
        }
    }


    vector_utils::display_vector(&array, size);
}

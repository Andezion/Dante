mod vector_utils;

fn main()
{
    let mut array:[i32; 150] = [0; 150];

    println!("Enter: ");
    let size: i32 = vector_utils::read_vector(&mut array, 150, 0);
    if size < 1
    {
        panic!("Not enough data available");
    }
    if size == 1
    {
        print!("{}", array[0]);
        return;
    }

    if vector_utils::bubble_sort(&mut array, size as usize) == 1
    {
        panic!("Incorrect input");
    }
}

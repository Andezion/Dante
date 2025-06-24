fn main()
{
    let array:[f32; 16] = [10.0, 11.0, 4.0, 5.0, 6.0, 12.0, 16.0, 1.0, 
                            2.0, 3.0, 13.0, 14.0, 15.0, 7.0, 8.0, 9.0];

    for i in (0..array.len()).step_by(2) 
    {
        print!("{} ", array[i]);
    }
    
    return;
}

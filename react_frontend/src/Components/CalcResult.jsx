const CalcResult = ({ value }) => 
{
    return (
        <span className="text-light fs-1 ps-5 mt-5">{(value || value === 0) && "= " + value}</span>
    );
}
 
export default CalcResult;
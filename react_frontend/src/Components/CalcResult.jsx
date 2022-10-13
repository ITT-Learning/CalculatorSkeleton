const CalcResult = ({ value, isValid }) => 
{
    const classValue = "result-box fs-0 align-self-center " + (isValid ? "text-light fst-none" : "text-danger fst-italic")
    return (
        <span className={classValue}>{((isValid ? "= " : "") + value)}</span>
    );
}
 
export default CalcResult;
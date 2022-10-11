const CalcInput = ({ value, handleChange, error }) =>
{
    return (
        <div className="pt-3 px-5">
            <div className="d-flex pb-3">
                <label htmlFor="calculator" className="text-light fs-4">Calculator Input</label>
                <span className="text-danger fs-4 ps-4 fst-italic">{error.length > 0 && error}</span>
            </div>
            <input
                type="text"
                id="calculator"
                className="form-control fs-2 fw-bold py-3"
                value={value}
                onChange={handleChange}
                placeholder="Enter equation here"
            />
        </div>
    );
}
 
export default CalcInput;
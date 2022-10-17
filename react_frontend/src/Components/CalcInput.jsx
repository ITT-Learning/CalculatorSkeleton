const CalcInput = ({ value, handleChange, handleSaveHistory }) =>
{
    return (
        <div className="pt-3 px-5">
            <div className="d-flex pb-3">
                <label htmlFor="calculator" className="text-light fs-4">Calculator Input</label>
            </div>
            <div class="input-group mb-3">
                <input
                    type="text"
                    id="calculator"
                    className="form-control fs-2 fw-bold py-3"
                    value={value}
                    onChange={handleChange}
                    placeholder="Enter equation here"
                    autoComplete="off"
                />
                <button class="input-group-text bg-danger fs-5" onClick={handleSaveHistory}>Save</button>
            </div>
        </div>
    );
}
 
export default CalcInput;

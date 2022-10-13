const HistoryEntry = ({ data, index }) =>
{
    const { equation, result } = data;
    return (
        <>
        <div className="d-flex flex-column ms-4">
            <span className="text-info fs-5">= {result}</span>
            <span className="text-muted fs-6 ps-3">{equation}</span>
        </div>
        <hr className="border-5 border-light" />
        </>
    );
}
 
export default HistoryEntry;
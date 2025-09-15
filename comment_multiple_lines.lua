Macro {
  description="Toggle comment (//) for selected lines or current line";
  area="Editor";
  key="Ctrl/";
  flags="";
  action=function()
    local ed = editor
    local sel = ed.GetSelection()

    local startLine, endLine
    if sel then
      startLine = sel.StartLine
      endLine   = sel.EndLine
    else
      local info = ed.GetInfo()
      startLine = info.CurLine
      endLine   = info.CurLine
    end

    local allCommented = true
    for i=startLine,endLine do
      local line = ed.GetString(nil, i).StringText
      if not line:match("^%s*//") then
        allCommented = false
        break
      end
    end

    for i=startLine,endLine do
      local line = ed.GetString(nil, i).StringText
      if allCommented then
        line = line:gsub("^(%s*)//", "%1", 1)
      else
        line = line:gsub("^(%s*)", "%1//", 1)
      end
      ed.SetString(nil, i, line)
    end
  end;
}

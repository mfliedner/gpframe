# == Schema Information
#
# Table name: tools
#
#  id         :integer          not null, primary key
#  executable :string
#  help       :string
#  name       :string
#  tooltip    :string
#  parameters :text
#  created_at :datetime         not null
#  updated_at :datetime         not null
#

require 'test_helper'

class ToolTest < ActiveSupport::TestCase
  # test "the truth" do
  #   assert true
  # end
end
